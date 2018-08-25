#!/bin/sh

set -ex

if [ ! -e mruby ]; then
    curl -L https://github.com/mruby/mruby/archive/1.4.1.zip -o mruby.zip
    unzip mruby.zip
    mv mruby-1.4.1 mruby
    rm mruby.zip
fi
cp build_config.rb mruby/build_config.rb
(cd mruby && make test)
