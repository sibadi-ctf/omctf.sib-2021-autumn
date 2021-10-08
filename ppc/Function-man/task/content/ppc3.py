import random
import hashlib
from fontTools.ttLib import TTFont
from flask import Flask, session, request, redirect, render_template
from flask_session import Session
from datetime import timedelta

app = Flask(__name__)
# Check Configuration section for more details
app.config["SESSION_PERMANENT"] = True
app.config["SESSION_TYPE"] = "filesystem"
app.config['PERMANENT_SESSION_LIFETIME'] = timedelta(hours=5)
app.config.from_object(__name__)
Session(app)

ALPHABET = list("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz")
FONT_ALPHABET = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']+list("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz")

@app.route("/", methods=["GET","POST"])
def index():
    if request.method == "GET":
        if not session.get("score"):
            session['score'] = '0'
        new_font = TTFont("/root/static/PTMono.ttf")
        new_alph = FONT_ALPHABET.copy()
        random.shuffle(new_alph)
        plain_text = ''.join(random.choices(ALPHABET+[' '], k=(random.randint(3400,5000) if not session['score'] == '0' else 15)))
        session['current_md5'] = hashlib.md5(plain_text.encode('utf-8')).hexdigest()
        for i in range(len(new_alph)):
            #app.logger.info(new_font['cmap'].tables[1].cmap[32])
            #app.logger.info(f"l1: {len(ALPHABET)}, l2: {len(new_alph)}")
            new_font['cmap'].tables[1].cmap[ord(ALPHABET[i])] = new_alph[i]
        font_hash = hashlib.md5(str(session.sid).encode('utf-8')).hexdigest()
        new_font.save('/root/static/'+font_hash+'.ttf')
        ciphered_text = ''
        for i in range(len(plain_text)):
            ciphered_text+=ALPHABET[new_alph.index(plain_text[i] if not plain_text[i] in "0123456789" else FONT_ALPHABET[int(plain_text[i])])] if not plain_text[i] == ' ' else ' '

            #create session font from PTMono
            #shuffle a-zA-Z0-9
            #generate original text, take md5
            #cipher it
            #app.logger.info('new session!')
        return render_template("index.html", ciphered_text=ciphered_text, font_hash=font_hash)
    if request.method == "POST":
        if not session.get("score"):
            return 'Bad session'
        if request.form['password'] == session['current_md5']:
            session['score'] = str(int(session['score'])+1)
            if int(session['score']) >= 1000:
                session['score'] = "0"
                return 'OmCTF{b3s7_md5_g1v3r_ev3R}'
            return redirect("/")
        else:
            return 'Bad hash'

#if __name__ == '__main__':
#    app.run(debug=True,host='0.0.0.0')
