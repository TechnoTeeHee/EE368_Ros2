from setuptools import find_packages, setup

package_name = 'ex13'

setup(
    name=package_name,
    version='1.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ark686',
    maintainer_email='ark686@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "control_turtle = ex13.control_turtle:main",
            "spawn_turtles = ex13.spawn_turtles:main",
            "turtle_monitor = ex13.turtle_monitor:main"
        ],
    },
)
