docker build -t web1 .
docker run --name cascade_resonance -dp 10001:80 web1