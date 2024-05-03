const express = require('express')
const app = express();
const port = 3000

//similar to fs.readFile, but for express
app.get('/', (req, res) => {
  res.send('Hello World!')
})

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})

//create  a todo app that lets users store todos on the server
//try to create a https from scratch in case you have time
