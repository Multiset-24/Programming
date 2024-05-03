//creating an http server using express

const express = require("express");

const app=express();

function sum(a,b){
    return a+b;
}
app.use(express.json());//middleware to parse the body of the request and using the syntax app.json() we are telling express to use this middleware for all the routes
app.get("/",(req,res)=>{
    let n=req.query.n;
    let m=req.query.m;
    let result=sum(parseInt(n),parseInt(m));
    res.send(`Hello saurav and the result is ${result}`);
    
});

app.post("/health-checkup",(req,res)=>{
    const kidneys=req.body.kidneys;
    const kidneylength=kidneys.length;

    res.send(`The length of kidneys is ${kidneylength}`);
})


//global catch all error handler- this should be the last middleware
//this will catch all the errors that are not caught by the previous middlewares
app.use((err,req,res,next)=>{
    console.log(err);
    res.status(501).send("Something went wrong");
}
);

//zod- validation library
app.listen(3000);

