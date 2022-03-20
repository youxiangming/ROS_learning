// Auto-generated. Do not edit!

// (in-package learning_topic.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Person {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.name = null;
      this.sex = null;
      this.age = null;
      this.age1 = null;
      this.height = null;
    }
    else {
      if (initObj.hasOwnProperty('name')) {
        this.name = initObj.name
      }
      else {
        this.name = '';
      }
      if (initObj.hasOwnProperty('sex')) {
        this.sex = initObj.sex
      }
      else {
        this.sex = 0;
      }
      if (initObj.hasOwnProperty('age')) {
        this.age = initObj.age
      }
      else {
        this.age = 0;
      }
      if (initObj.hasOwnProperty('age1')) {
        this.age1 = initObj.age1
      }
      else {
        this.age1 = 0;
      }
      if (initObj.hasOwnProperty('height')) {
        this.height = initObj.height
      }
      else {
        this.height = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Person
    // Serialize message field [name]
    bufferOffset = _serializer.string(obj.name, buffer, bufferOffset);
    // Serialize message field [sex]
    bufferOffset = _serializer.uint8(obj.sex, buffer, bufferOffset);
    // Serialize message field [age]
    bufferOffset = _serializer.uint8(obj.age, buffer, bufferOffset);
    // Serialize message field [age1]
    bufferOffset = _serializer.uint16(obj.age1, buffer, bufferOffset);
    // Serialize message field [height]
    bufferOffset = _serializer.float64(obj.height, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Person
    let len;
    let data = new Person(null);
    // Deserialize message field [name]
    data.name = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [sex]
    data.sex = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [age]
    data.age = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [age1]
    data.age1 = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [height]
    data.height = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.name.length;
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'learning_topic/Person';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8cf74e85a44e7a35ab62353a46e326a3';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string name
    uint8 sex
    uint8 age
    
    uint8 unknown =0
    uint8 male=1
    uint8 female=2
    
    uint16 age1
    float64 height
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Person(null);
    if (msg.name !== undefined) {
      resolved.name = msg.name;
    }
    else {
      resolved.name = ''
    }

    if (msg.sex !== undefined) {
      resolved.sex = msg.sex;
    }
    else {
      resolved.sex = 0
    }

    if (msg.age !== undefined) {
      resolved.age = msg.age;
    }
    else {
      resolved.age = 0
    }

    if (msg.age1 !== undefined) {
      resolved.age1 = msg.age1;
    }
    else {
      resolved.age1 = 0
    }

    if (msg.height !== undefined) {
      resolved.height = msg.height;
    }
    else {
      resolved.height = 0.0
    }

    return resolved;
    }
};

// Constants for message
Person.Constants = {
  UNKNOWN: 0,
  MALE: 1,
  FEMALE: 2,
}

module.exports = Person;
