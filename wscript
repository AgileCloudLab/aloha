#! /usr/bin/env python
# encoding: utf-8
from waflib.Tools.compiler_cxx import cxx_compiler

APPNAME = 'aloha'
VERSION = '1.0.0'


cxx_compiler['linux'] = ['clang++']

def options(opt):
    opt.load('compiler_cxx')

def configure(cnf) :
    cnf.load('compiler_cxx')
    cnf.env.append_value('CXXFLAGS', ['-std=c++17', '-Wall', '-Werror', '-Wextra'])
    cnf.env.append_value('LINKFLAGS',
                         ['-pthread'])


def build(bld):



    bld(name = 'aloha_includes',
        includes='./src',
        export_includes='./src'
    )

    bld.recurse('test/test_log_to_auto_file')
    bld.recurse('test/test_log_to_custom_file')
    bld.recurse('test/test_log_to_iostream')
    bld.recurse('test/test_log_to_cerr')
    bld.recurse('test/test_logging_on_off')    
