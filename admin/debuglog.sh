#!/bin/bash

minicom -D $(ls /dev/tty.usbmodem*) -b 115200