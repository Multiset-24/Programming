//creating an http server using express

const express = require("express");

const app=express();

function sum(a,b){
    return a+b;
}
app.get("/",(req,res)=>{
    let n=req.query.n;
    let m=req.query.m;
    let result=sum(parseInt(n),parseInt(m));
    res.send(`Hello saurav and the result is ${result}`);
    
});

app.listen(3000);

