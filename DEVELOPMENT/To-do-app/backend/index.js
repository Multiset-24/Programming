//write basuc express boilerplate code here
//with express.json() middleware

const express = require("express");
const app = express();
const { CreateTodo, UpdateTodo } = require("./types");
const { todo } = require("./db");
const cors=require("cors");
app.use(express.json());
app.use(cors({}));


app.get("/todos", async (req, res) => {
  const todos = await todo.find({});
  res.json({
    todos,
  });
});

app.post("/todo", async (req, res) => {
  const createpayload = req.body.createpayload;
  const parsedpayload = CreateTodo.safeParse(createpayload);

  if (!parsedpayload.success) {
    res.status(411).json({
      msg: "you sent the wrong input",
    });
    return;
  }

  await todo.create({
    title: createpayload.title,
    description: createpayload.description,
    completed: false,
  });

  res.json({
    msg: "Todo created",
  });
  //put it in mongodb
});

app.put("/completed", async (req, res) => {
  const updatepayload = req.body.updatepayload;
  const parsedpayload = UpdateTodo.safeParse(updatepayload);

  if (!parsedpayload.success) {
    res.status(411).json({
      msg: "you sent the wrong input",
    });
    return;
  }
  await todo.update(
    {
      _iq: req.body._id
    },
    {
      completed: true,
    }
  );

  res.json({
    msg: "todo marked",
  });
});

// module.exports=app;
app.listen(3000);
