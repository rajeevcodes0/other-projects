//importing libraries
import ReactDOM from 'react-dom';

//importing context provider
import { AppDataProvider } from './store/app-data';

import './index.css';
import App from './App';

ReactDOM.render(<AppDataProvider><App /></AppDataProvider>, document.getElementById('root'));
