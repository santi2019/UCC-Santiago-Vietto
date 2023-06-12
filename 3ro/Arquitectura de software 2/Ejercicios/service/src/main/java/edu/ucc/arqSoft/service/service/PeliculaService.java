package edu.ucc.arqSoft.service.service;



import java.util.ArrayList;
import java.util.Set;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import edu.ucc.arqSoft.service.dao.PeliculaDao;
import edu.ucc.arqSoft.service.dto.PeliculaResponseDto;
import edu.ucc.arqSoft.service.model.Pelicula;
import edu.ucc.arqSoft.service.common.dao.GenericDao;

@Service
@Transactional
public class PeliculaService {
	
	@Autowired
	private PeliculaDao peliculaDao;
	
	public PeliculaResponseDto getPeliculaById (Long id) {
		
		Pelicula pelicula = peliculaDao.load(id);
		
		PeliculaResponseDto dto = new PeliculaResponseDto();
		dto.setNombre(pelicula.getTitulo());
		dto.setGenero(pelicula.getGenero().toString().toLowerCase());
		dto.setId(id);
		
		return dto;
		
	}
	
	
	public List<PeliculaResponseDto> getPeliculas() {

		List<Pelicula> peliculas = peliculaDao.getAll();
		
		List<PeliculaResponseDto> dtos = new ArrayList<PeliculaResponseDto>();
		
		PeliculaResponseDto dto;
		for (Pelicula pelicula : peliculas) {
			dto = new PeliculaResponseDto();
			dto.setNombre(pelicula.getTitulo());
			dto.setGenero(pelicula.getGenero().toString().toLowerCase());
			dto.setId(pelicula.getId());
			
			dtos.add(dto);
		}
		
		return dtos;
	}
	
}
