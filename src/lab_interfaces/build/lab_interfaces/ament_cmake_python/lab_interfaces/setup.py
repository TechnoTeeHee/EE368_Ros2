from setuptools import find_packages
from setuptools import setup

setup(
    name='lab_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('lab_interfaces', 'lab_interfaces.*')),
)