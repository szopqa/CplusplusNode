/* Example taken from : https://github.com/nodejs/node-addon-examples */
const addon = require('bindings')('lists_addon');

const obj1 = addon.createObject(10);
const obj2 = addon.createObject(20);
const result = addon.add(obj1, obj2);

console.log(result); // 30
