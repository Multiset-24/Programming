import { useState } from 'react'

import './App.css'

function App() {
  const [Color,setColor]=useState("orange")

  return (
    <div style={{
      backgroundColor: Color,
      height: '100vh', // Viewport height
      width: '100vw', // Viewport width
      margin: 0, // Remove default margin
      padding: 0, // Remove default padding
      display: 'flex', // Use flexbox for centering (optional)
      justifyContent: 'space-around', // Center horizontally (optional)
      alignItems: 'center', // Center vertically (optional)
      flexDirection:"row",
      gap:'2em'
    }}>
        <button className="text-white bg-red-500 hover:bg-red-700 font-bold py-2 px-4 rounded border border-4 border-red-700" onClick={()=>setColor("red")}>red</button>
        <button className="text-white bg-blue-500 hover:bg-blue-700 font-bold py-2 px-4 rounded border border-4 border-blue-700" onClick={()=>setColor("blue")}>blue</button>
        <button className="text-white bg-green-500 hover:bg-green-700 font-bold py-2 px-4 rounded border border-4 border-green-700" onClick={()=>setColor("green")}>green</button>
        <button className="text-white bg-yellow-500 hover:bg-yellow-700 font-bold py-2 px-4 rounded border border-4 border-yellow-700" onClick={()=>setColor("yellow")}>yellow</button>
        <button className="text-white bg-purple-500 hover:bg-purple-700 font-bold py-2 px-4 rounded border border-4 border-purple-700" onClick={()=>setColor("violet")}>violet</button>
        <button className="text-white bg-indigo-500 hover:bg-indigo-700 font-bold py-2 px-4 rounded border border-4 border-indigo-700" onClick={()=>setColor("indigo")}>indigo</button>
        <button className="text-white bg-orange-500 hover:bg-orange-700 font-bold py-2 px-4 rounded border border-4 border-orange-700" onClick={()=>setColor("orange")}>orange</button>
    </div>
  )
}

export default App
