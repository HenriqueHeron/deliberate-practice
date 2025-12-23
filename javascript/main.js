let dog = { name: 'doggo', sayName() { console.log(this.name); } };
let sayName = dog.sayName;
sayName.call(dog)
// sayName.apply(dog)
// sayName = sayName.bind(dog)