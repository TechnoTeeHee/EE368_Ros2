# generated from rosidl_generator_py/resource/_idl.py.em
# with input from lab_interfaces:srv/MeasureWallDist.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MeasureWallDist_Request(type):
    """Metaclass of message 'MeasureWallDist_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('lab_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'lab_interfaces.srv.MeasureWallDist_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__measure_wall_dist__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__measure_wall_dist__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__measure_wall_dist__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__measure_wall_dist__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__measure_wall_dist__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MeasureWallDist_Request(metaclass=Metaclass_MeasureWallDist_Request):
    """Message class 'MeasureWallDist_Request'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

import builtins  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_MeasureWallDist_Response(type):
    """Metaclass of message 'MeasureWallDist_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('lab_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'lab_interfaces.srv.MeasureWallDist_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__measure_wall_dist__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__measure_wall_dist__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__measure_wall_dist__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__measure_wall_dist__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__measure_wall_dist__response

            from lab_interfaces.msg import WallDistanceArray
            if WallDistanceArray.__class__._TYPE_SUPPORT is None:
                WallDistanceArray.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MeasureWallDist_Response(metaclass=Metaclass_MeasureWallDist_Response):
    """Message class 'MeasureWallDist_Response'."""

    __slots__ = [
        '_wall_dist_array',
    ]

    _fields_and_field_types = {
        'wall_dist_array': 'lab_interfaces/WallDistanceArray',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['lab_interfaces', 'msg'], 'WallDistanceArray'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from lab_interfaces.msg import WallDistanceArray
        self.wall_dist_array = kwargs.get('wall_dist_array', WallDistanceArray())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.wall_dist_array != other.wall_dist_array:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def wall_dist_array(self):
        """Message field 'wall_dist_array'."""
        return self._wall_dist_array

    @wall_dist_array.setter
    def wall_dist_array(self, value):
        if __debug__:
            from lab_interfaces.msg import WallDistanceArray
            assert \
                isinstance(value, WallDistanceArray), \
                "The 'wall_dist_array' field must be a sub message of type 'WallDistanceArray'"
        self._wall_dist_array = value


class Metaclass_MeasureWallDist(type):
    """Metaclass of service 'MeasureWallDist'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('lab_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'lab_interfaces.srv.MeasureWallDist')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__measure_wall_dist

            from lab_interfaces.srv import _measure_wall_dist
            if _measure_wall_dist.Metaclass_MeasureWallDist_Request._TYPE_SUPPORT is None:
                _measure_wall_dist.Metaclass_MeasureWallDist_Request.__import_type_support__()
            if _measure_wall_dist.Metaclass_MeasureWallDist_Response._TYPE_SUPPORT is None:
                _measure_wall_dist.Metaclass_MeasureWallDist_Response.__import_type_support__()


class MeasureWallDist(metaclass=Metaclass_MeasureWallDist):
    from lab_interfaces.srv._measure_wall_dist import MeasureWallDist_Request as Request
    from lab_interfaces.srv._measure_wall_dist import MeasureWallDist_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
