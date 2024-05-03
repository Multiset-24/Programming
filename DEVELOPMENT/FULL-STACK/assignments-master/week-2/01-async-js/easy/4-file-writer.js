const fs=require('fs');

//This is how you  write to a file

fs.writeFile('FULL-STACK\\assignments-master\\week-2\\01-async-js\\easy\\a.txt','Hello World',(err)=>{
    if(err){
        console.log(err);
    }
    else console.log('File written successfully');
});

