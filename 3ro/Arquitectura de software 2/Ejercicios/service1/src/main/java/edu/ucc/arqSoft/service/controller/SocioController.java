/*package edu.ucc.arqSoft.service.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.ResponseStatus;

import edu.ucc.arqSoft.service.dto.SocioRequestDto;
import edu.ucc.arqSoft.service.dto.SocioResponseDto;
import edu.ucc.arqSoft.service.service.SocioService;

@Controller
@RequestMapping("/socio")
public class SocioController {

	@Autowired
	private SocioService socioService;
	
	
	@RequestMapping(value = "/{id}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody ResponseEntity<Object> lookupById(@PathVariable("id") Long id) {
			SocioResponseDto dto = socioService.getSocioById(id);

			return new ResponseEntity<Object>(dto, HttpStatus.OK);	
			
	}
	
	@RequestMapping(value = "/all", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody ResponseEntity<Object> getSocios() {
		
		List<SocioResponseDto> dtos = socioService.getSocios();

		return new ResponseEntity<Object>(dtos, HttpStatus.OK);
	}
	
	@RequestMapping(method = RequestMethod.POST, consumes = MediaType.APPLICATION_JSON_VALUE, produces = MediaType.APPLICATION_JSON_VALUE)
	@ResponseStatus(code = HttpStatus.CREATED)
	public @ResponseBody SocioResponseDto registrar(@RequestBody SocioRequestDto request) {
		
		return socioService.registrar(request);
		
	}
	
}
*/