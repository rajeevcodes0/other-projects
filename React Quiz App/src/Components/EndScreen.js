import React from 'react';

import './EndScreen.css';

const EndScreen = (props) => {
    return(
        <div className="end-screen">
            <p>{`Well Done ${props.playerName}. Your Score is ${props.points}`}</p>
        </div>
    );
}

export default EndScreen;