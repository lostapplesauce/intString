// import logo from '../logo.svg';
// import './App.css';
import data from './data'
import './stylesheets/App.css'
import Header from './components/Header'
import Jobs from './components/Jobs'
import Profile from './components/Profile'
import Bits from './components/Bits'

// File where the page is rendered

export default function App() {
  const jobs = data.map(item => {
    return (
      <Jobs
        key={item.id}
        job={item.job}
        date={item.date}
        description={item.description}
      />
    )
    
  })
  
  return (
    <div className="App">
      <Header />
      {jobs}
      <Profile />
      <Bits />
    </div>
  );
}
