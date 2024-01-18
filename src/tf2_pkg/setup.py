from setuptools import find_packages, setup

package_name = 'tf2_pkg'

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
    maintainer_email='teehee@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "tf_broadcaster1 = tf2_pkg.tf_broadcaster1:main",
            "tf_broadcaster2 = tf2_pkg.tf_broadcaster2:main",
            "tf_broadcaster3 = tf2_pkg.tf_broadcaster3:main",
            "tf_broadcaster_ex14 = tf2_pkg.tf_broadcaster_ex14:main",
            "tf_broadcaster4 = tf2_pkg.tf_broadcaster4:main",
            "tf_listener = tf2_pkg.tf_listener:main",
            "tf_listener1 = tf2_pkg.tf_listener1:main",
            "tf_listener2 = tf2_pkg.tf_listener2:main",
            "transform_point = tf2_pkg.transform_point:main"
        ],
    },
)
