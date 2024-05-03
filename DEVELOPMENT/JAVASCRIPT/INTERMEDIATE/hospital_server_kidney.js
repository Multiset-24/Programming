const express = require("express");
const app = express();

const person = [
  {
    name: "john",
    age: 20,
    kidneys: [
      {
        side: "left",
        condition: "good",
      },
      {
        side: "right",
        condition: "good",
      },
    ],
  },
  {
    name: "jane",
    age: 25,
    kidneys: [
      {
        side: "left",
        condition: "good",
      },
    ],
  },
  {
    name: "joe",
    age: 30,

    kidneys: [
      {
        side: "left",
        condition: "good",
      },
      {
        side: "right",
        condition: "bad",
      },
    ],
  },
];

app.use(express.json());

app.get("/", (req, res) => {//get request to get the details of the user
    const user_id = req.query.user_id;
    if(user_id >=person.length){
        res.send("Invalid user_id")
    }
    const user = person[parseInt(user_id)];
    const name = user.name;
    const age = user.age;

    const number_of_kidneys = user.kidneys.length;
  
    const left_kidney = user.kidneys.find((kidney) => kidney.side === "left");
    const right_kidney = user.kidneys.find((kidney) => kidney.side === "right");

    res.json({
      name,
      age,
      number_of_kidneys,
      left_kidney: left_kidney ? left_kidney.condition : "Not available",
      right_kidney: right_kidney ? right_kidney.condition : "Not available",
    });
  });

app.post("/", (req, res) => {//
  const user_id = req.body.user_id;
  const side = req.body.side;
  if(user_id >=person.length){
    res.send("Invalid user_id")
}
  const user = person[user_id];

  if (user.kidneys.length < 2) {
    user.kidneys.push({
      side: side,
      condition: "good",
    });
    res.send("done");
  } else {
    res.send("A person can't have more than 2 kidneys");
  }
});

app.delete("/", (req, res) => {
    const user_id = req.body.user_id;
    const side = req.body.side;
    const user = person[user_id];
    if(user_id >=person.length){
      res.send("Invalid user_id")
  }
    const kidneyToDeleteIndex = user.kidneys.findIndex((kidney) =>{
       return  kidney.side === side
});
    if (kidneyToDeleteIndex !== -1) {
      user.kidneys.splice(kidneyToDeleteIndex, 1);
      res.send("done");
    } else {
      res.send("Kidney not applicable for deletion");
    }
  });
  
  app.put("/", (req, res) => {
    const user_id = req.body.user_id;
    const side = req.body.side;
    const condition = req.body.condition;
    const user = person[user_id];
    if(user_id >=person.length){
      res.send("Invalid user_id")
  }
    const kidneyToUpdate = user.kidneys.find((kidney) => kidney.side === side);
    if (kidneyToUpdate) {
      kidneyToUpdate.condition = condition;
      res.send("done");
    } else {
      res.send("Kidney not applicable for update");
    }
  });

app.listen(3001);
