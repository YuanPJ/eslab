var util = require('util');

var bleno = require('bleno');

var sensor = require('node-dht-sensor');

var BlenoCharacteristic = bleno.Characteristic;

var EchoCharacteristic = function() {
  EchoCharacteristic.super_.call(this, {
    uuid: 'ec02',
    properties: ['read'],
    value: null
  });

  this._data = new Buffer(0);
  this._updateValueCallback = null;
};

util.inherits(EchoCharacteristic, BlenoCharacteristic);

var temp = 0, hum = 0;

EchoCharacteristic.prototype.onReadRequest = function(offset, callback) {
    sensor.read(11, 4, (err, temperature, humidity) => {
	    temp = temperature;
	    hum = humidity;
      temp.toFixed(1);
      hum.toFixed(1);
    })
	this._data = new Buffer(2);
	this._data.fill(0);
	this._data.writeInt8(temp, 0);
	this._data.writeInt8(hum, 1);
    
 console.log('EchoCharacteristic - onReadRequest: value = ' + temp.toString() + hum.toString());

  callback(this.RESULT_SUCCESS, this._data);
};

module.exports = EchoCharacteristic;
