const express=require("express");
const app=express();
const zod=require("zod");
const mongoose=require("mongoose");

function ticket_checker(req,res,next){
    if(req.query.age<=16){
        res.json({
            message:"You are not allowed to enter the park"
        })
    }
    else{
        next();
    }
}

app.use(ticket_checker);//middleware this will be called for every request

app.get("/",(req,res)=>{
    res.send("Welcome to the amusement park");
});

app.get("/rides",ticket_checker,(req,res)=>{
    res.send("You can enjoy the rides");
});

app.listen(3000,()=>{
    console.log("Server is running on port 3000");
});