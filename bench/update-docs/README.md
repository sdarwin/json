
## Update benchmark documentation

A script to update the doc/ directory with new benchmarks results.

## Instructions

To isolate the process, launch a docker container and continue there:

```
docker run -it ubuntu:22.04 bash
apt-get update
apt-get install -y git vim
```

Checkout the codebase and switch to a feature branch:

```
mkdir -p /opt/github/boostorg
cd /opt/github/boostorg
git clone https://github.com/boostorg/json
cd json
git checkout -b update_docs
```

Change to the update-docs directory:  

```
cd bench/update-docs/
```

Review the script update-docs.sh. This script does not run the benchmarks. It's purpose is to take a set of benchmarks results and update the docs.    

As a detour, how are the benchmark results generated? Most simply, by building the bench executable and then  

```
./bench *.json
```

In update-docs.sh you can either set a URL link at the beginning "benchresultsfile=" to download a file, or manually place the file in "tmp/benchresults.txt". The format of that file should be as found in json/doc/bench/results.html  

Then, run the script:  

```
./update-docs.sh
```

It refreshes the files in docs/images  

Check in the files:  

```
git add .
git commit -m "Newer benchmark docs"
git push
```
