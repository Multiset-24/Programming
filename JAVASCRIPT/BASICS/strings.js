/* THIS IS FOR THE METHODS OF STRINGS */

let _name="saurav ";
let name1=" Hello World  ";

// 1. length- returns the length of the string
console.log(name1.length); // returns 11

// 2. toUpperCase- returns the string in uppercase
console.log(name1.toUpperCase());// returns HELLO WORLD

// 3. toLowerCase- returns the string in lowercase
console.log(name1.toLowerCase());// returns hello world     

// 4. charAt- returns the character at the specified index
console.log(name1.charAt(0));// returns H

// 5. indexOf- returns the index of the first occurrence of the specified value
console.log(name1.indexOf("W")); // returns 7

// 6. lastIndexOf- returns the index of the last occurrence of the specified value
console.log(name1.lastIndexOf("o")); // returns 8   

// 7. startsWith- returns true if the string starts with the specified value, otherwise false
console.log(name1.startsWith(" w"));

// 8. endsWith- returns true if the string ends with the specified value, otherwise false
console.log(name1.endsWith(" d"));


// 9. includes- returns true if the string contains the specified value, otherwise false
console.log(name1.includes("World")); 

// 10. slice- returns the extracted part of a string
console.log(name1.slice(0,5));// returns Hello
console.log(name1.slice(0));// returns Hello World
console.log(name1.slice(0,-4));// returns Hello beacuse -4 is the index from the end

// 11. substring- returns the extracted part of a string
console.log(name1.substring(0,5)); // returns Hello

// 12. substr  - returns the extracted part of a string
console.log(name1.substr(0,5)); // returns Hello

// 13. replace- replaces a specified value with another value in a string
console.log(name1.replace("World","dunia"));
// 14. repeat- returns a new string with a specified number of copies of an existing string

// 15. trim- removes whitespace from both ends of a string
console.log(name1.trim());
// 16. split- splits a string into an array of substrings

// 17. concat- joins two or more strings
console.log(_name.concat(name1)); 

console.log(name1+" "+_name); // using + operator


// 18. match- searches a string for a match against a regular expression, and returns the matches

// 19. search- searches a string for a specified value, and returns the position of the match

// 20. localeCompare- compares two strings in the current locale

// 21. fromCharCode- converts Unicode values to characters

// 22. codePointAt- returns the Unicode of the character at the specified index

// 23. normalize- returns the Unicode Normalization Form of a given string

// 24. padStart- pads the current string with another string until the resulting string reaches the given length

// 25. padEnd- pads the current string with another string until the resulting string reaches the given length

// 26. anchor- creates an HTML anchor

// 27. big- creates a big text
console.log(name1.big());// returns <big>Hello World</big>

// 28. blink- creates a blinking text
console.log(name1.blink());// returns <blink>Hello World</blink>

// 29. bold- creates a bold text
console.log(name1.bold());// returns <b>Hello World</b>

// 30. fixed- creates a teletype text
 console.log(name1.fixed());// returns <tt>Hello World</tt>

// 31. fontcolor- creates a colored text
console.log(name1.fontcolor("red"));// returns <font color="red">Hello World</font>

// 32. fontsize- creates a text with a specified size
console.log(name1.fontsize(7));// returns <font size="7">Hello World</font>

// 33. italics- creates an italic text

// 34. link- creates an HTML link

// 35. small- creates a small text

// 36. strike- creates a strikethrough text

// 37. sub- creates a subscript text
console.log(name1.sub());// returns <sub>Hello World</sub>

// 38. sup- creates a superscript text
console.log(name1.sup());// returns <sup>Hello World</sup>

// 39. charCodeAt- returns the Unicode of the character at the specified index

// 40. localeCompare- compares two strings in the current locale

// 41. toLocaleLowerCase- returns the string in lowercase, according to the host's locale

// 42. toLocaleUpperCase- returns the string in uppercase, according to the host's locale

// 43. valueOf- returns the primitive value of a string object

// 44. toString- returns the value of a String object
let num=45;
console.log(num.toString());// converts number to string


// 45. trimStart- removes whitespace from the beginning of a string
console.log(name1.trimStart());// returns Hello World  (removes the whitespace from the beginning of the string

// 46. trimEnd- removes whitespace from the end of a string
console.log(name1.trimEnd());// returns  Hello World (removes the whitespace from the end of the string

// 47. at- returns the character at the specified index
console.log(name1.at(2));// returns e

// 48. codePointAt- returns the Unicode of the character at the specified index

// 49. normalize- returns the Unicode Normalization Form of a given string


