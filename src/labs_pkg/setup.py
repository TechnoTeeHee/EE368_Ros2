from setuptools import find_packages, setup

package_name = 'labs_pkg'

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
            "turtlesim_move = labs_pkg.turtlesim_move:main",
            "turtlesim_scan = labs_pkg.turtlesim_scan:main",
            "turtlesim_stop_at_wall = labs_pkg.turtlesim_stop_at_wall:main",
            "tb4_stop_at_wall = labs_pkg.tb4_stop_at_wall:main",
            "turtlesim_circles = labs_pkg.turtlesim_circles:main",
            "tb4_circles = labs_pkg.tb4_circles:main",
            "control_turtle = labs_pkg.control_turtle:main",
            "my_talker = labs_pkg.my_talker:main",
            "my_listener = labs_pkg.my_listener:main",
            "integer_publisher = labs_pkg.integer_publisher:main",
            "cumulative_adder = labs_pkg.cumulative_adder:main",
            "add2ints_server = labs_pkg.add2ints_server:main",
            "add2ints_client_no_oop = labs_pkg.add2ints_client_no_oop:main",
            "add2ints_client = labs_pkg.add2ints_client:main",
            "wall_dist_measurement = labs_pkg.wall_dist_measurement:main",
            "wall_dist_statistics = labs_pkg.wall_dist_statistics:main",
            "wall_dist_measurement_server = labs_pkg.wall_dist_measurement_server:main",
            "wall_dist_statistics_client = labs_pkg.wall_dist_statistics_client:main",
            "integer_array_publisher = labs_pkg.integer_array_publisher:main",
            "array_adder = labs_pkg.array_adder:main",
            "turtle_monitor = labs_pkg.turtle_monitor:main",
            "spawn_turtles = labs_pkg.spawn_turtles:main",
            "turtlesim_odom = labs_pkg.turtlesim_odom:main",
            "turtlesim_drivesquare = labs_pkg.turtlesim_drivesquare:main"
        ],
    },
)
