docker build -t web3 .
docker run --name errorology -dp 10003:8080 web3