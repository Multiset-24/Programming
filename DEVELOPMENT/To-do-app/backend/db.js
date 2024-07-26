/*
        Todo{
        title:string;
        description:string
        completed:boolean
        }
*/

const mongoose=require("mongoose");
mongoose.connect("mongodb+srv://souravtechx98:Saurav%402305@cluster0.drxeamg.mongodb.net/");
const todoschema=mongoose.Schema({
    title:String,
    description:String,
    completed:Boolean
})

const todo=mongoose.model(
    'todo',todoschema
);

module.exports={
    todo
}