# CDR 2017

This is arduino source code for robot of team Les Cools Girls

I re-write source code of my grandfather in more readable source code :)

## Init project

To init project, need to init submodule and npm tools :

```bash
$ git submodule update --init
$ npm install
```

## Serial

Serial Speed is 115200 bauds

## pinout

Pinout of program is in file pinout.hpp

## Version

Number of version is send on serial when start.
Version number is git hash and tag (create define in Makefile).
