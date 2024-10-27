FROM ubuntu

RUN apt-get update && apt-get install -y \
  gcc g++ make valgrind vim libgtest-dev check

COPY . /code

WORKDIR /code

CMD /bin/bash
