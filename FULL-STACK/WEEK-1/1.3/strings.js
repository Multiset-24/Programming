let str="saurav";
console.log(str.length);

//indexOf, lastIndexOf , length of string
function findIndex(str,target){
    console.log("Original string",str);
    console.log("index:",str.lastIndexOf(target));//use of index of of a word 
}
findIndex("hello saurav hello ","hello");

// Slice and substr(now discarded)
function getSlice(str,start,end){
    console.log(str.slice(start,end));//slice function

}

function getsubstr(str,start,length){
    console.log(str.substr(start,length));
}
getSlice(str,0,6);
getsubstr(str,0,5)

//replace a char or sub-string with a new substring or char

let newstr="hello, world";
console.log(newstr);
console.log(newstr.replace("world","saurav"));

//split-this basically stores the every word in a string in an array seperately like "hello saurav" if  we use split then we will get ["hello","saurav"]
console.log(newstr.split("  "));
console.log(newstr.split(", "));//"," this is called delimeter on the basis of which an array gets splitted


//trim---->this is used to trim the extra space from front and back of the string

let Trim="    hello     saurav   ";
console.log(Trim);
console.log(Trim.trim());

//toUpperCase and toLowerCase

let t="hello";
console.log(t.toUpperCase());




