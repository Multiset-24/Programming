import { useState } from "react";
import CustomButton from "./components/Button"


//jsx file
function App() {
  const [count, setCount] = useState(0); //react hook

  return (
    <div>
      <h1 className="text-3xl font-bold underline">
      Hello world!
    </h1>
      <CustomButton count={count} setCount={setCount} />
    </div>
  );
}


export default App;
