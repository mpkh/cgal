// Copyright (c) 2003  INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
// 
//
// Author(s)     : Mariette Yvinec, Sylvain Pion

#ifndef CGAL_TRIANGULATION_VERTEX_BASE_WITH_INFO_2_H
#define CGAL_TRIANGULATION_VERTEX_BASE_WITH_INFO_2_H

#include <CGAL/Triangulation_vertex_base_2.h>

CGAL_BEGIN_NAMESPACE

template < typename Info_, typename GT,
           typename Vb = Triangulation_vertex_base_2<GT> >
class Triangulation_vertex_base_with_info_2
  : public Vb
{
  Info_ _info;

public:
  typedef typename Vb::Face_handle                   Face_handle;
  typedef typename Vb::Point                         Point;
  typedef Info_                                      Info;

  template < typename TDS2 >
  struct Rebind_TDS {
    typedef typename Vb::template Rebind_TDS<TDS2>::Other          Vb2;
    typedef Triangulation_vertex_base_with_info_2<Info, GT, Vb2>   Other;
  };

  Triangulation_vertex_base_with_info_2()
    : Vb() {}

  Triangulation_vertex_base_with_info_2(const Point & p)
    : Vb(p) {}

  Triangulation_vertex_base_with_info_2(const Point & p, Face_handle c)
    : Vb(p, c) {}

  Triangulation_vertex_base_with_info_2(Face_handle c)
    : Vb(c) {}

  const Info& info() const { return _info; }
  Info&       info()       { return _info; }
};

template <typename Info_, class GT, class Vb >
std::ostream&
operator<<(std::ostream &os, const Triangulation_vertex_base_with_info_2<Info_, GT, Vb> &v)
  // non combinatorial information. Default = point
{
  return os << static_cast<const Vb&>(v)  << " " << v.info();
}

template <typename Info_, class GT, class Vb >
std::istream&
operator>>(std::istream &is, Triangulation_vertex_base_with_info_2<Info_, GT, Vb> &v)
  // non combinatorial information. Default = point
{
 return is >> static_cast<Vb&>(v)  >> v.info();
}
CGAL_END_NAMESPACE

#endif // CGAL_TRIANGULATION_VERTEX_BASE_WITH_INFO_2_H
