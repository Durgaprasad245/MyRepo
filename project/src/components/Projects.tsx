import React from 'react';
import { ExternalLink, Github } from 'lucide-react';

const Projects = () => {
  const projects = [
    {
      title: 'E-Commerce Platform',
      description: 'A full-stack e-commerce solution with React and Node.js',
      image: 'https://images.unsplash.com/photo-1557821552-17105176677c?auto=format&fit=crop&q=80&w=800',
      technologies: ['React', 'Node.js', 'PostgreSQL', 'Redux'],
      githubLink: 'https://github.com',
      liveLink: 'https://example.com',
    },
    {
      title: 'Task Management App',
      description: 'Collaborative task management tool with real-time updates',
      image: 'https://images.unsplash.com/photo-1557804506-669a67965ba0?auto=format&fit=crop&q=80&w=800',
      technologies: ['React', 'Firebase', 'Tailwind CSS'],
      githubLink: 'https://github.com',
      liveLink: 'https://example.com',
    },
    {
      title: 'Weather Dashboard',
      description: 'Real-time weather tracking with interactive maps',
      image: 'https://images.unsplash.com/photo-1592210454359-9043f067919b?auto=format&fit=crop&q=80&w=800',
      technologies: ['React', 'OpenWeather API', 'Chart.js'],
      githubLink: 'https://github.com',
      liveLink: 'https://example.com',
    },
  ];

  return (
    <div className="py-16 px-4 sm:px-6 lg:px-8 max-w-7xl mx-auto">
      <h2 className="text-3xl font-bold mb-12 text-center bg-clip-text text-transparent bg-gradient-to-r from-primary-600 to-secondary-600">Featured Projects</h2>
      <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-8">
        {projects.map((project, index) => (
          <div key={index} className="bg-white/60 backdrop-blur-sm rounded-xl shadow-lg overflow-hidden transform hover:-translate-y-1 transition-all duration-300 hover:shadow-xl border border-primary-100/30">
            <div className="relative">
              <div className="absolute inset-0 bg-gradient-to-br from-primary-600/20 to-secondary-600/20 mix-blend-overlay"></div>
              <img
                src={project.image}
                alt={project.title}
                className="w-full h-48 object-cover"
              />
            </div>
            <div className="p-6">
              <h3 className="text-xl font-semibold text-primary-900 mb-2">{project.title}</h3>
              <p className="text-gray-600 mb-4">{project.description}</p>
              <div className="flex flex-wrap gap-2 mb-4">
                {project.technologies.map((tech, i) => (
                  <span
                    key={i}
                    className="px-3 py-1 bg-gradient-to-r from-primary-100 to-secondary-100 text-primary-700 rounded-full text-sm font-medium"
                  >
                    {tech}
                  </span>
                ))}
              </div>
              <div className="flex space-x-4">
                <a
                  href={project.githubLink}
                  target="_blank"
                  rel="noopener noreferrer"
                  className="flex items-center text-primary-600 hover:text-primary-700 transition-colors duration-200"
                >
                  <Github className="w-5 h-5 mr-2" />
                  Code
                </a>
                <a
                  href={project.liveLink}
                  target="_blank"
                  rel="noopener noreferrer"
                  className="flex items-center text-primary-600 hover:text-primary-700 transition-colors duration-200"
                >
                  <ExternalLink className="w-5 h-5 mr-2" />
                  Live Demo
                </a>
              </div>
            </div>
          </div>
        ))}
      </div>
    </div>
  );
};

export default Projects;