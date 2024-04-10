const fs=require('fs');

fs.readFile('FULL-STACK\\assignments-master\\week-2\\01-async-js\\easy\\a.txt','utf8',(err,data)=>{
    if(err){
        console.log(err);
    }
    console.log(data);
});

for(let i=0;i<1000;i++){
    console.log(i);
}

