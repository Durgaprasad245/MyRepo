import React, { useState } from 'react';
import { Home, User, Briefcase, FileText, BookOpen, Github, Linkedin, Mail } from 'lucide-react';
import About from './components/About';
import Projects from './components/Projects';
import Resume from './components/Resume';
import Blogs from './components/Blogs';
import HomePage from './components/HomePage';

function App() {
  const [activeSection, setActiveSection] = useState('home');

  const navigation = [
    { name: 'HOME', icon: Home, id: 'home' },
    { name: 'ABOUT', icon: User, id: 'about' },
    { name: 'PROJECTS', icon: Briefcase, id: 'projects' },
    { name: 'RESUME', icon: FileText, id: 'resume' },
    { name: 'BLOGS', icon: BookOpen, id: 'blogs' },
  ];

  const renderSection = () => {
    switch (activeSection) {
      case 'home':
        return <HomePage />;
      case 'about':
        return <About />;
      case 'projects':
        return <Projects />;
      case 'resume':
        return <Resume />;
      case 'blogs':
        return <Blogs />;
      default:
        return <HomePage />;
    }
  };

  return (
    <div className="min-h-screen bg-gradient-to-br from-primary-50 via-white to-secondary-50">
      {/* Navigation */}
      <nav className="fixed top-0 w-full bg-white/80 backdrop-blur-md shadow-sm z-50">
        <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
          <div className="flex justify-between h-16">
            <div className="flex space-x-8">
              {navigation.map((item) => (
                <button
                  key={item.id}
                  onClick={() => setActiveSection(item.id)}
                  className={`inline-flex items-center px-1 pt-1 text-sm font-medium border-b-2 transition-colors duration-200 ${
                    activeSection === item.id
                      ? 'border-primary-600 text-primary-700'
                      : 'border-transparent text-gray-500 hover:border-primary-300 hover:text-primary-600'
                  }`}
                >
                  <item.icon className="w-4 h-4 mr-2" />
                  {item.name}
                </button>
              ))}
            </div>
            
            {/* Social Links */}
            <div className="flex items-center space-x-4">
              <a href="https://github.com" target="_blank" rel="noopener noreferrer" className="text-gray-400 hover:text-primary-600 transition-colors duration-200">
                <Github className="w-5 h-5" />
              </a>
              <a href="https://linkedin.com" target="_blank" rel="noopener noreferrer" className="text-gray-400 hover:text-primary-600 transition-colors duration-200">
                <Linkedin className="w-5 h-5" />
              </a>
              <a href="mailto:your.email@example.com" className="text-gray-400 hover:text-primary-600 transition-colors duration-200">
                <Mail className="w-5 h-5" />
              </a>
            </div>
          </div>
        </div>
      </nav>

      {/* Main Content with enhanced background */}
      <div className="fixed inset-0 bg-gradient-to-br from-primary-50 via-white to-secondary-50 -z-10"></div>
      <div className="fixed inset-0 bg-[url('https://images.unsplash.com/photo-1618005182384-a83a8bd57fbe?auto=format&fit=crop&q=80&w=2000')] opacity-[0.03] -z-10"></div>
      <main className="pt-16 relative">
        {renderSection()}
      </main>
    </div>
  );
}

export default App;