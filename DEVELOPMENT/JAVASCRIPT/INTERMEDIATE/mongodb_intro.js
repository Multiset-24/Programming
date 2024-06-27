//this is just the basic intro to mongodb which includes the connection to the database and the basic CRUD operations
const express=require('express');
const app=express();
const mongoose=require('mongoose');
const { userInfo } = require('os');

mongoose.connect('mongodb+srv://souravtechx98:Saurav%402305@cluster0.drxeamg.mongodb.net/');
const user=mongoose.model('User_data',{
    name:{
        type:String,
        required:true
    },
    email:{
        type:String,
        required:true
    },
    password:{
        type:String,
        required:true
    }
});


app.use(express.json());

const zod=require('zod');

app.post('/signup',async function(req,res){
    const name=req.body.name;
    const email=req.body.email;
    const password=req.body.password;

    const user_exist=await user.findOne({
        email:email
    });


    if(user_exist){
        return res.status(400).json({
            msg:"email is already in use"
        });
    }
    else{
        const User=new user({
            name:name,
            email:email,
            password:password
        });

        User.save();
        return res.status(200).json({
            msg:"User created successfully"
        });
    }
});

app.post('/login',async function(req,res){
    const email=req.body.email;
    const password=req.body.password;

    const user_exist=await user.findOne({
        email:email,
        password:password
    });

    if(user_exist){
        return res.status(200).json({
            msg:"User logged in successfully"
        });
    }
    else{
        return res.status(400).json({
            msg:"Invalid email or password"
        });
    }
});

app.post('/delete',async function(req,res){
    const email=req.body.email;
    const password=req.body.password;

    const user_exist=await user.findOne({
        email:email,
        password:password
    });

    if(user_exist){
        user.deleteOne({//deleting the user from the database
            email:email,
            password:password
        });
        return res.status(200).json({
            msg:"User deleted successfully"
        });
    }
    else{
        return res.status(400).json({
            msg:"Invalid email or password"
        });
    }
});

app.listen(3000,()=>{
    console.log("server is running on port 3000");
});
