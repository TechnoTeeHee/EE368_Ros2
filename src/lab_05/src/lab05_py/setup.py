from setuptools import find_packages, setup

package_name = 'lab05_py'

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
    maintainer='rgz834',
    maintainer_email='rgz834@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "depth_camera = lab05_py.depth_camera:main",
            "keyboard_control = lab05_py.keyboard_control:main",
        ],
    },
)