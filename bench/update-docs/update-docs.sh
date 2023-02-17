#!/bin/bash

#
# A script to update the benchmarks in the documentation.
#
# See the README.md in this directory for instructions.
#
# ./update-docs.sh
#

set -e
set -x

benchresultsfile="https://benchmark.cppalliance.org/archive/one-time/2023-02-16-basic"

echo "Install apt packages"
apt-get update
# apt-get install -y nginx-extras npm curl wget sudo libnss3 libatk1.0-0 libatk-bridge2.0-0 libcups2 libxkbcommon-x11-0 firefox
apt-get install -y nginx-extras npm curl wget sudo libnss3 firefox libgbm-dev
sudo service nginx start

echo "Install node packages"
# npm install puppeteer@9.1.1
npm install

mkdir -p tmp
if [ -n "$benchresultsfile" ]; then
    echo "Downloading benchmarks"
    curl -s -S -L -o tmp/benchresults.txt $benchresultsfile
fi

# It is also possible to directly place a file in tmp/benchresults.txt

if [ ! -f tmp/benchresults.txt ]; then
    echo "Place a benchmark results file in tmp/benchresults.txt before continuing."
    echo "Exiting".
    exit 1
fi

cat template-part1.html > tmp/results.html
cat tmp/benchresults.txt >> tmp/results.html
cat template-part2.html >> tmp/results.html

cp tmp/results.html ../
cp tmp/results.html /var/www/html/

echo "Running puppeteer"
node puppeteer1.js

echo "Copying png images to doc directory"
cp tmp/*.png ../../doc/images
