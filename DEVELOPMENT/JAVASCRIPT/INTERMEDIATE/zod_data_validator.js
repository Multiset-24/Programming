//Zod is a library which 
const express=require("express");
const zod=require("zod");
const app=express();

function sum(a,b){
    return a+b;
}

app.use(express.json());//middleware to parse the body of the request and using the syntax app.json() we are telling express to use this middleware for all the routes

//how zod works
//what is schema-schemas are the blueprints of the data that we are going to validate
//zod.string() is a function which will return a schema for the string
//zod.array() is a function which will return a schema for the array
//zod.object() is a function which will return a schema for the object
//zod.number() is a function which will return a schema for the number
//zod.boolean() is a function which will return a schema for the boolean
//zod.null() is a function which will return a schema for the null
//zod.undefined() is a function which will return a schema for the undefined
//zod.any() is a function which will return a schema for any type of value
//zod.unknown() is a function which will return a schema for the unknown type of value
//zod.union() is a function which will return a schema for the union of the values
//zod.intersection() is a function which will return a schema for the intersection of the values
//zod.tuple() is a function which will return a schema for the tuple of the values
//zod.record() is a function which will return a schema for the record of the values
//zod.promise() is a function which will return a schema for the promise of the values
//zod.function() is a function which will return a schema for the function of the values
//zod.lazy() is a function which will return a schema for the lazy of the values
//zod.transform() is a function which will return a schema for the transform of the values
//zod.optional() is a function which will return a schema for the optional of the values
//zod.nullable() is a function which will return a schema for the nullable of the values
//zod.default() is a function which will return a schema for the default of the values
//zod.refine() is a function which will return a schema for the refine of the values

const schema=zod.array(zod.string());//creating a schema for the kidneys

const schema2=zod.object({
    name:zod.string(),
    email:zod.string().email(),
    phone_number:zod.string().min(10).max(10),
    age:zod.number().int().positive()
});//creating a schema for the user


app.post("/health-checkup",(req,res)=>{
    const user=req.body.user;
    const kidneys=req.body.kidneys;
    const kidneylength=kidneys.length;
    const response=schema.safeParse(user);
    /**
     difference between parse and safeParse
        parse will throw an error if the data is not valid
        safeParse will not throw an error if the data is not valid instead it will return an object with the error property

        response.error will be undefined if the data is valid
        response.error will be an object if the data is not valid

        example:
        const response=schema.parse(user);
        if(response.error){
            res.status(400).send("Invalid data");
        }

        const response=schema.safeParse(user);
        if(response.error){
            res.status(400).send("Invalid data");
        }

     */

    res.send(`The length of kidneys is ${kidneylength}`);
});

//global catch all error handler- this should be the last middleware
//this will catch all the errors that are not caught by the previous middlewares
app.use((err,req,res,next)=>{
    console.log(err);
    res.status(501).send("Something went wrong");
});


app.listen(3000);

