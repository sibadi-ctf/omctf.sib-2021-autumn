import random
import rstr
jackpot = random.randint(10000,90000)
for i in range(99999):
    if i == jackpot:
        print(rstr.xeger(r'OmCTF{[a-zA-Z0-9_]{30,40}}'))
    print(rstr.xeger(r'OmCTF{[a-zА-Я0-9_]{10,50}}'))