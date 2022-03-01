import React from 'react';

import styles from './Warning.module.css';

const Warning = ()=>{
    return(
        <div className={styles.warning}>
            <p>Oops! Seems like you have entered a wrong city name!</p>
        </div>
    );
}

export default Warning;