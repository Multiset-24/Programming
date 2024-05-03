const express=require("express");

const app=express();

function sum(a,b){
    return a+b;
}

app.use(express.json());//middleware to parse the body of the request and using the syntax app.json() we are telling express to use this middleware for all the routes

function checkBody(req,res,next){
    if(req.body.kidneys){
        next();
    }
    else{
        res.status(400).send("Kidneys are not present in the body");
    }
}

function checkKidneyLength(req,res,next){
    if(req.body.kidneys.length<=2){
        next();
    }
    else{
        res.status(400).send("Kidneys are not enough");
    }
}

app.post("/health-checkup",checkBody,checkKidneyLength,(req,res)=>{
    const kidneys=req.body.kidneys;
    const kidneylength=kidneys.length;

    res.send(`The length of kidneys is ${kidneylength}`);
});

//global catch all error handler- this should be the last middleware
//this will catch all the errors that are not caught by the previous middlewares
app.use((err,req,res,next)=>{
    console.log(err);
    res.status(501).send("Something went wrong");
});


app.listen(3000);

