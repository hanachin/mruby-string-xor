mruby-string-xor   [![Build Status](https://travis-ci.org/hanachin/mruby-string-xor.svg?branch=master)](https://travis-ci.org/hanachin/mruby-string-xor)
====

Add String#^(other) method that return XOR of two strings.

Installation
----

Add this line to build_config.rb

```ruby
MRuby::Build.new do |conf|
  conf.gem github: 'hanachin/mruby-string-xor'
end
```

or add this line to you aplication's mrbgem.rake

```ruby
MRuby::Gem::Specification.new('your-mrbgem') do |spec|
  spec.add_dependency 'mruby-string-xor', github: 'hanachin/mruby-string-xor'
end
```


Usage
----

```ruby
'わーい！' ^ 'わーい！'
# => '\0'
```

How to execute test
----

    $ git clone https://github.com/hanachin/mruby-string-xor.git
    $ cd mruby-string-xor
    $ ./test.sh

License
----

MIT
