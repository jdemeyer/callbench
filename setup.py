#!/usr/bin/env python

import os
from setuptools import setup, Extension

opj = os.path.join

extensions = [Extension("callbench.callables", [opj("src", "callbench", "callables.c")])]

setup(
    name='callbench',
    version='1.0',
    description='Benchmarking CPython calling conventions',
    author='Jeroen Demeyer',
    author_email='J.Demeyer@UGent.be',
    license='3-clause BSD',
    url="https://github.com/jdemeyer/callbench",
    install_requires=['perf'],
    packages=['callbench'],
    package_dir={'callbench': opj("src", "callbench")},
    ext_modules=extensions,
)
