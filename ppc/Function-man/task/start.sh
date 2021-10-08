docker build -t ppc3 .
docker run --name function_man -dp 10007:10007 ppc3
