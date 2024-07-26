import React from 'react';

function CustomButton(props){
  function increase() {
    if (props.count >= 20) {
      alert("not possible");
      return;
    }
    props.setCount(props.count + 1);
  }

  function decrease() {
    if (props.count <= 0) {
      alert("not possible");
      return;
    }
    props.setCount(props.count - 1);
  }

  return (
    <div>
      <h1>counter {props.count}</h1><br />
      <button onClick={increase}>increase</button><br />
      <button onClick={decrease}>decrease</button>
    </div>
  );
}


export default CustomButton;
