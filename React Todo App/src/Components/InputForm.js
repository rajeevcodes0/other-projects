import React from 'react';

import './InputForm.css';

const InputForm = (props) => {
    return(
        <form onSubmit={props.onAddTask}>
            <input value={props.inputValue} onChange={props.onInputChange}type="text"/>
            <button type="submit" ><i class="fas fa-plus"></i></button>
        </form>
    );
}

export default InputForm;