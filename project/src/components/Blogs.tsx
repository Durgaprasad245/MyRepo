import React from 'react';
import { Clock, ArrowRight } from 'lucide-react';

const Blogs = () => {
  const blogs = [
    {
      title: 'Modern React Best Practices in 2024',
      excerpt: 'Exploring the latest patterns and practices in React development',
      date: 'March 15, 2024',
      readTime: '5 min read',
      image: 'https://images.unsplash.com/photo-1633356122544-f134324a6cee?auto=format&fit=crop&q=80&w=800',
    },
    {
      title: 'Building Scalable Frontend Architecture',
      excerpt: 'A comprehensive guide to structuring large-scale React applications',
      date: 'March 10, 2024',
      readTime: '8 min read',
      image: 'https://images.unsplash.com/photo-1618761714954-0b8cd0026356?auto=format&fit=crop&q=80&w=800',
    },
    {
      title: 'The Future of Web Development',
      excerpt: 'Insights into upcoming trends and technologies in web development',
      date: 'March 5, 2024',
      readTime: '6 min read',
      image: 'https://images.unsplash.com/photo-1617042375876-a13e36732a04?auto=format&fit=crop&q=80&w=800',
    },
  ];

  return (
    <div className="py-16 px-4 sm:px-6 lg:px-8 max-w-7xl mx-auto">
      <h2 className="text-3xl font-bold mb-12 text-center bg-clip-text text-transparent bg-gradient-to-r from-primary-600 to-secondary-600">Latest Blog Posts</h2>
      <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-8">
        {blogs.map((blog, index) => (
          <article key={index} className="bg-white/60 backdrop-blur-sm rounded-xl shadow-lg overflow-hidden transform hover:-translate-y-1 transition-all duration-300 hover:shadow-xl border border-primary-100/30">
            <div className="relative">
              <div className="absolute inset-0 bg-gradient-to-br from-primary-600/20 to-secondary-600/20 mix-blend-overlay"></div>
              <img
                src={blog.image}
                alt={blog.title}
                className="w-full h-48 object-cover"
              />
            </div>
            <div className="p-6">
              <div className="flex items-center text-gray-500 text-sm mb-2">
                <span>{blog.date}</span>
                <span className="mx-2">•</span>
                <span className="flex items-center">
                  <Clock className="w-4 h-4 mr-1" />
                  {blog.readTime}
                </span>
              </div>
              <h3 className="text-xl font-semibold text-primary-900 mb-2">{blog.title}</h3>
              <p className="text-gray-600 mb-4">{blog.excerpt}</p>
              <a
                href="#"
                className="inline-flex items-center text-primary-600 hover:text-primary-700 transition-colors duration-200"
              >
                Read More
                <ArrowRight className="w-4 h-4 ml-2" />
              </a>
            </div>
          </article>
        ))}
      </div>
    </div>
  );
};

export default Blogs;