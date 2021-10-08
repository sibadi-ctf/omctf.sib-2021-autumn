FROM trafex/php-nginx:latest
RUN ["rm","-rf","/var/www/html/*"]
COPY ./content /var/www/html
EXPOSE 8080