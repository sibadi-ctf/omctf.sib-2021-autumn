FROM ubuntu
RUN apt update && apt upgrade -y
RUN apt install python3 python3-pip -y
RUN pip3 install flask flask-session fonttools waitress
COPY ./content/ppc3.py /root/
COPY ./content/wtrs.py /root/
COPY ./content/index.html /root/templates/
COPY ./content/PTMono.ttf /root/static/
WORKDIR /root/
EXPOSE 10007
ENTRYPOINT python3 wtrs.py
