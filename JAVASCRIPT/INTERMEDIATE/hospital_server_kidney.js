const express=require("express");
const app=express();

const person=[{
    name:"john",
    age:20,
    kidneys:[{
        left:"good"
    },{
        right:"good"
    }]
},{
    name:"doe",
    age:30,
    kidneys:[{
        left:"good"
    },{
        right:"good"
    }]
},{
    name:"jane",
    age:40,
    kidneys:[{
        left:"good"
    },{
        right:"good"
    }]
},{
}]

app.use(express.json());

app.get("/",(req,res)=>{
    const user_id=req.query.user_id;
    const user=person[parseInt(user_id)];
    const name=user.name;
    const age=user.age;

    const number_of_kidneys=user.kidneys.length;

    const left_kidney=user.kidneys[0].left;
    const right_kidney=user.kidneys[1].right;
    
    res.json({
        name,
        age,
        number_of_kidneys,
        left_kidney,
        right_kidney
    })

});

app.post("/",(req,res)=>{
    const user_id=req.body.user_id;
    const ishealthy=req.body.ishealthy;

    const user=person[user_id];

    user.kidneys.push({
        extra:ishealthy
    }
    );

    res.send("done");

}
)

app.delete("/",(req,res)=>{
    const user_id=req.body.user_id;
    const user=person[user_id];
    user.kidneys.pop();
    res.send("done");
}
)

app.put("/",(req,res)=>{
    const user_id=req.body.user_id;
    const user=person[user_id];
    user.kidneys[0].left="bad";
    res.send("done");
}
)



app.listen(3001);

