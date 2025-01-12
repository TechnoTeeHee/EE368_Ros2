from setuptools import find_packages, setup

package_name = 'pylab04'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='teehee',
    maintainer_email='tahakaleemmalhi@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "stop_at_wall = pylab04.stop_at_wall:main",
            "around_wall = pylab04.around_wall:main",
            "go_to_red = pylab04.go_to_red:main"
        ],
    },
)
