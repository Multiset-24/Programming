const fs=require ('fs');

//This is how you clean  from a file

let data;

fs.readFile('FULL-STACK//assignments-master//week-2//01-async-js//medium//a.txt','utf8',(err,dat)=>{
    if(err){
        console.log(err);
    }
    data=dat;
    data=data.replace(/\s+/g, ' ');
    fs.writeFile('FULL-STACK//assignments-master//week-2//01-async-js//medium//a.txt',data,(err)=>{
        if(err){
            console.log(err);
        }
        console.log('File cleaned successfully');
    });
});