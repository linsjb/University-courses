/**
* Course: DT096G
* Moment: Laboration 2
* Autor: Linus Sjöbro
* Created: 2019-03-19
*
* Description: Explore the JavaScript prototype paradigm
* and how to modify the js functions.
*/

let Iterator = function(array){
  this.index = 0;
  this.array = array;
}

Iterator.prototype.next = function() {
  return this.array[this.index++];
}

Iterator.prototype.hasNext = function() {
  return this.index <= this.array.length -1;
}

Iterator.prototype.reset = function() {
  this.index = 0;
}

Array.prototype.iterator = function() {
  return new Iterator(this);
}

var data = [1,2,3,4,5,6];
iterator = data.iterator();

while(iterator.hasNext()) {
  console.log(iterator.next());
}
